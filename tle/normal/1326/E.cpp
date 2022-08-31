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
#define SZ 1234567
int n,p[SZ],q[SZ],r[SZ],ans[SZ];
const int M=524288;
int su[SZ],ms[SZ];
void mark(int x,int y)
{
//	cout<<"mark"<<x<<" "<<y<<"?\n";
	x+=M; su[x]+=y; ms[x]=min(su[x],0);
	while(x>>=1)
		su[x]=su[x+x]+su[x+x+1],
		ms[x]=min(ms[x+x],su[x+x]+ms[x+x+1]);
}
bool chk()
{
	return su[1]>ms[1];
}
void get_ans(int ql,int qr,int al,int ar)
{
	if(ql>qr) return;
	int qm=(ql+qr)>>1;
//	cout<<"testing "<<qm<<"\n";
//	cout<<chk()<<"?\n";
	//everything <ql has been marked
	//everything >ar has been marked
	for(int i=ql;i<=qm;++i)
		if(i) mark(q[i],-1);
	int am=ar;
	while(1)
	{
		mark(r[am],1);
		if(chk()) break;
		--am;
	}
//	cout<<"EZ"<<qm<<"->"<<am<<"\n";
	ans[qm]=am;
	mark(r[am],-1);
	get_ans(qm+1,qr,al,am);
	for(int i=am+1;i<=ar;++i)
		mark(r[i],-1);
	for(int i=ql;i<=qm;++i)
		if(i) mark(q[i],1);
	get_ans(ql,qm-1,am,ar);
}
void main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i],r[p[i]]=i;
	for(int i=1;i<=n;++i)
		cin>>q[i];
	//can the answer be >=something?
	//a single query:
	//mark all q[i]<=lim be -1
	//all p[i]>=bound be +1
	get_ans(0,n-1,1,n);
	for(int i=0;i<n;++i)
		cout<<ans[i]<<" ";
}


#undef main
#ifndef ONLINE_JUDGE
void rmv_() {remove("IN_TEMP_E_Dt4Bfiv");remove("OUT_TEMP_E_Dt4Bfiv");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}int main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_E_Dt4Bfiv");o<<in; o.close();freopen("IN_TEMP_E_Dt4Bfiv","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_E_Dt4Bfiv","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_E_Dt4Bfiv");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
#else
int main(){fakemain();}
#endif
/*
*o* Sample Input 1:
3
3 2 1
1 2 3
*o* Sample Output 1:
3 2 1 
*o* Sample Input 2:
6
2 3 6 1 5 4
5 2 1 4 6 3
*o* Sample Output 2:
6 5 5 5 4 1 
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/