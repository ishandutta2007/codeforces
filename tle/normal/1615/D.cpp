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
int t,n,m,bad=0;
Edgc
vector<pii> te[SZ];
int col[SZ];
void dfs(int x,int u) {
	if(col[x]!=-1&&col[x]==u) {
		return;
	}
	if(col[x]!=-1&&col[x]!=u) {
		bad=1;
		return;
	}
	col[x]=u;
	for(auto w:te[x]) if(w.se!=-1) {
		dfs(w.fi,u^(__builtin_popcount(w.se)&1));
	}
	for esb(x,e,b)
		dfs(b,u^vc[e]);
}
int v[SZ];
void dfst(int x,int f=0) {
	for(auto w:te[x]) {
		if(f==w.fi) continue;
		if(w.se!=-1)
			v[w.fi]=v[x]^w.se;
		else
			v[w.fi]=v[x]^(col[x]^col[w.fi]);
		dfst(w.fi,x);
	}
}
void main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	cin>>t;
	while(t--) {
		cin>>n>>m;
		M=0;
		for(int i=1;i<=n;++i) fst[i]=0,te[i].clear();
		for(int i=1,x,y,v;i<n;++i) {
			cin>>x>>y>>v;
			te[x].pb(pii(y,v));
			te[y].pb(pii(x,v));
		}
		for(int i=1;i<=m;++i) {
			int a,b,p;
			cin>>a>>b>>p;
			adde(a,b,p);
		}
		for(int i=1;i<=n;++i) col[i]=-1;
		bad=0;
		for(int i=1;i<=n;++i) if(col[i]==-1) dfs(i,0);
		if(bad) {
			cout<<"NO\n";
			continue;
		}
		dfst(1);
		cout<<"YES\n";
		for(int i=1;i<=n;++i)
			for(auto e:te[i])
			{
				int b=e.fi;
				if(i>=b) continue;
				cout<<i<<" "<<b<<" "<<(v[i]^v[b])<<"\n";
			}
	}
	
}


#undef main
#ifndef ONLINE_JUDGE
void rmv_() {remove("IN_TEMP_D_ykmBdk8");remove("OUT_TEMP_D_ykmBdk8");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}int main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_D_ykmBdk8");o<<in; o.close();freopen("IN_TEMP_D_ykmBdk8","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_D_ykmBdk8","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_D_ykmBdk8");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
#else
int main(){fakemain();}
#endif
/*
*o* Sample Input 1:
4
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1
2 4 0
3 4 1
2 3 1
3 3
1 2 -1
1 3 -1
1 2 0
1 3 1
2 3 0
2 1
1 2 1
1 2 0
*o* Sample Output 1:
YES
1 2 0
1 3 1
2 4 7
3 6 0
2 5 0
YES
1 2 1
1 3 0
1 4 1
4 5 1
NO
NO
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/