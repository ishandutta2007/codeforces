#define main fakemain
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 209999
int m,n;
vector<int> a,b,w;
struct Basis
{
int g[5],ok;
void ins(int x)
{
	if(ok) return;
	for(int j=4;j>=0;--j) if(x&(1<<j))
	{
		if(g[j]) {x^=g[j]; continue;}
		for(int k=0;k<j;++k)
			if(x&(1<<k)) x^=g[k];
		for(int k=j+1;k<5;++k)
			if(g[k]&(1LL<<j)) g[k]^=x;
		g[j]=x; return;
	}
	ok=1;
}
};
Basis merge(Basis a,Basis b)
{
	if(a.ok) return a;
	if(b.ok) return b;
	for(auto w:b.g)
		if(w) a.ins(w);
	return a;
}
bool operator < (Basis a,Basis b)
{
	if(a.ok!=b.ok)
		return a.ok<b.ok;
	if(a.ok) return 0;
	for(int i=0;i<5;++i)
		if(a.g[i]!=b.g[i])
			return a.g[i]<b.g[i];
	return 0;
}
map<Basis,int> g;
Basis ry[888];
int sg[32],an=0,tr[888][32],mg[888][888],O;
int dfs(Basis b)
{
	if(g.count(b)) return g[b];
	int x=++an; ry[an]=b; g[b]=x;
	if(b.ok) O+=x;
	for(int i=0;i<32;++i)
	{
		Basis c=b;
		c.ins(i);
		tr[x][i]=dfs(c);
	}
	return x;
}
Edgc
bool vis[SZ],vvv[SZ];
int tv[SZ],de[SZ],mc[SZ];
vector<int> down_cyc[SZ];
void dd(int x,int tt=0,int fe=0)
{
	vis[x]=1;
	for esb(x,e,b) if(vc[e]!=fe)
	{
		if(vvv[vc[e]]) continue;
//		cout<<x<<"->"<<b<<"\n";
		vvv[vc[e]]=1;
		if(x==1) ++de[b];
		if(vis[b])
		{
			int cv=(tv[b]^tv[x]^w[vc[e]]);
			if(b==1) mc[tt]=cv,++de[tt];
			else down_cyc[tt].pb(cv);
//			cout<<"cyc"<<tt<<","<<(tv[b]^tv[x]^w[vc[e]])<<"\n";
		}
		else
			tv[b]=tv[x]^w[vc[e]],
			dd(b,(tt==0)?b:tt,vc[e]);
	}
}
void main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	Basis ww;
	memset(&ww,0,sizeof ww);
	dfs(ww);
	for(int i=0;i<32;++i)
	{
		Basis l=ww;
		l.ins(i);
		sg[i]=g[l];
		assert(sg[i]!=0);
	}
	for(int i=1;i<=an;++i)
		for(int j=1;j<=an;++j)
		{
			Basis w=merge(ry[i],ry[j]);
			mg[i][j]=g[w];
			assert(mg[i][j]!=0);
		}
//	cerr<<O<<" "<<an<<"?\n";
	cin>>n>>m;
	a.resize(m+1);
	b.resize(m+1);
	w.resize(m+1);
	for(int i=1;i<=m;++i) {
		cin>>a[i]>>b[i]>>w[i];
		adde(a[i],b[i],i);
	}
	dd(1);
	static ll f[2][400];
	const int MOD=1e9+7;
	int c=0; f[0][1]=1;
	for(int i=2;i<=n;++i)
	{
		assert(de[i]<=2);
		if(de[i]==1)
		{
//			cerr<<i<<"!\n";
			//either cut or accept
			int u=1;
			for(auto w:down_cyc[i])
				u=mg[u][sg[w]];
			c^=1;
			memcpy(f[c],f[c^1],sizeof f[c]);
//			for(int i=0;i<400;++i)
//				if(f[!c][i]) cout<<i<<":"<<f[!c][i]<<"\n";
			for(int i=0;i<400;++i)
				if(f[!c][i]) (f[c][mg[u][i]]+=f[!c][i])%=MOD;
//			for(int i=0;i<400;++i)
//				if(f[c][i]) cout<<i<<":"<<f[c][i]<<"B\n";
		}
		else if(de[i]==2)
		{
//			cout<<"??"<<i<<"\n";
			int u=1;
			for(auto w:down_cyc[i])
//				cout<<sg[w]<<",",
				u=mg[u][sg[w]];
			int v=sg[mc[i]];
//			cout<<"  "<<mc[i]<<"    "<<O<<","<<u<<","<<v<<"\n";
			c^=1;
			memcpy(f[c],f[c^1],sizeof f[c]);
			for(int i=0;i<400;++i)
				if(f[!c][i])
					(f[c][mg[u][i]]+=f[!c][i]*2LL)%=MOD,
					(f[c][mg[u][mg[v][i]]]+=f[!c][i])%=MOD;
		}
	}
	int ans=0;
	for(int i=0;i<400;++i)
		if(i!=O) (ans+=f[c][i])%=MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}


#undef main
#ifndef ONLINE_JUDGE
void rmv_() {remove("IN_TEMP_D_vo8M75y");remove("OUT_TEMP_D_vo8M75y");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}int main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_D_vo8M75y");o<<in; o.close();freopen("IN_TEMP_D_vo8M75y","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_D_vo8M75y","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_D_vo8M75y");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
#else
int main(){fakemain();}
#endif
/*
*o* Sample Input 1:
6 8
1 2 0
2 3 1
2 4 3
2 6 2
3 4 8
3 5 4
5 4 5
5 6 6
*o* Sample Output 1:
2
*o* Sample Input 2:
7 9
1 2 0
1 3 1
2 3 9
2 4 3
2 5 4
4 5 7
3 6 6
3 7 7
6 7 8
*o* Sample Output 2:
1
*o* Sample Input 3:
4 4
1 2 27
1 3 1
1 4 1
3 4 0
*o* Sample Output 3:
6
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/