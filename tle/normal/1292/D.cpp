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
#define SZ 666666
int n;
vector<int> k;
const int U=5000;
int ps[SZ],pn;
bool np[SZ];
struct in;
int gid(const in&u);
struct in {int c[700],d,id;
void gd()
{
	d=0;
	for(int i=1;i<=pn;++i)
		d+=c[i];
	id=gid(*this);
}
ll gv() const
{
	ll x=1;
	for(int i=1;i<=pn;++i)
		for(int j=c[i];j;--j) x*=ps[i];
	return x;
}
};
map<in,int> ids;
int an=0,iid[SZ];
int gid(const in&u)
{
	if(ids.count(u)) return ids[u];
	ids[u]=++an,iid[an]=u.d; return an;
}
in fac(int w)
{
	in g;
	for(int i=1;i<=pn;++i)
	{
		int p=ps[i],t=w,s=0;
		while(t/=p) s+=t;
		g.c[i]=s;
	}
	g.gd();
	return g;
}
in glca(in x,const in& y)
{
	int i;
	for(i=pn;i>=1;--i)
		if(x.c[i]!=y.c[i]) break;
	for(int j=1;j<i;++j) x.c[j]=0;
	x.c[i]=min(x.c[i],y.c[i]); x.gd();
	return x;
}
bool operator != (const in&a,const in&b)
{
	for(int i=1;i<=pn;++i)
		if(a.c[i]!=b.c[i]) return 1;
	return 0;
}
bool operator < (const in&a,const in&b)
{
	for(int i=1;i<=pn;++i)
		if(a.c[i]!=b.c[i])
			return a.c[i]<b.c[i];
	return 0;
}
int vfa[12345],idi[12345],cv[12345];
in st[12345],vs[12345]; int vn,stn;
Edgc
int sz[SZ];
ll ind[SZ],oud[SZ];
void dfs(int x,int f=0)
{
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x),sz[x]+=sz[b];
		ind[x]+=ind[b]+sz[b]*(ll)vc[e];
	}
	sz[x]+=cv[x];
}
ll ans=8e18;
void dfs2(int x,int f=0)
{
	for esb(x,e,b) if(b!=f)
	{
		oud[b]=oud[x]+ind[x]-ind[b]-sz[b]*(ll)vc[e]+vc[e]*(ll)(n-sz[b]);
		dfs2(b,x);
	}
	ans=min(ans,ind[x]+oud[x]);
//	cout<<x<<":"<<sz[x]<<"w"<<n-sz[x]<<"  "<<ind[x]<<","<<oud[x]<<"\n";
}
void main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	for(int i=2;i<=U;++i) if(!np[i])
	{
		ps[++pn]=i;
		for(int j=i;j<=U;j+=i) np[j]=1;
	}
	//debug only!!
	for(int i=1;i<=5000;++i)
	{
		in x=fac(i); idi[i]=x.id;
		if(!stn) {st[++stn]=x; vfa[x.id]=0; continue;}
		in lca=glca(x,st[stn]);
		for(;st[stn].d>lca.d;--stn)
			if(st[stn-1].d<=lca.d) vfa[st[stn].id]=lca.id;
		if(st[stn]!=lca)
		{
			vs[++vn]=lca;
			vfa[lca.id]=st[stn].id;
			st[++stn]=lca;
		}
        vfa[x.id]=lca.id;
		st[++stn]=x;
//		cout<<i<<","<<stn<<" "<<vn<<"\n";
	}
	for(int i=1;i<=an;++i) if(vfa[i])
		adde(i,vfa[i],iid[i]-iid[vfa[i]]);
//	for(int i=1;i<=an;++i)
//	{
//		cout<<i<<"->"<<vfa[i]<<" "<<iix[i].gv()<<" "<<iid[i]-iid[vfa[i]]<<"\n";
//	}
	cin>>n;
	k.resize(n);
	for(int i=0;i<n;++i) {
		cin>>k[i];
		if(!k[i]) ++k[i];
		++cv[idi[k[i]]];
	}
	dfs(1); dfs2(1);
	cout<<ans<<"\n";
}


#undef main
#ifndef ONLINE_JUDGE
void rmv_() {remove("IN_TEMP_D_mEXFCQ3");remove("OUT_TEMP_D_mEXFCQ3");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}int main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_D_mEXFCQ3");o<<in; o.close();freopen("IN_TEMP_D_mEXFCQ3","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_D_mEXFCQ3","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_D_mEXFCQ3");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
#else
int main(){fakemain();}
#endif
/*
*o* Sample Input 1:
3
2 1 4
*o* Sample Output 1:
5
*o* Sample Input 2:
4
3 1 4 4
*o* Sample Output 2:
6
*o* Sample Input 3:
4
3 1 4 1
*o* Sample Output 3:
6
*o* Sample Input 4:
5
3 1 4 1 5
*o* Sample Output 4:
11
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/