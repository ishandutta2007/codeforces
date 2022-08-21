#define main fakemain
#include <bits/stdc++.h>
using namespace std;
#define SZ 666666
int n,c,a[SZ];
typedef long long ll;
ll mx[SZ],S[SZ];
void main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	scanf("%d%d",&n,&c);
	ll su=0;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),su+=a[i];
	//smallest for each c?
	static int qs[SZ]; int h=0,t=0;
	for(int i=1;i<=n;++i)
	{
		while(h!=t&&a[qs[t-1]]>a[i])
			--t;
		qs[t++]=i;
		while(qs[h]<i-c+1) ++h;
		S[i]=a[qs[h]];
	}
	for(int i=c;i<=n;++i)
		mx[i]=max(mx[i-c]+S[i],mx[i-1]);
	cout<<su-mx[n]<<"\n";
}


#undef main
#ifndef ONLINE_JUDGE
void rmv_() {remove("IN_TEMP_E_w4ehq0K");remove("OUT_TEMP_E_w4ehq0K");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}int main(int argc,char**argv){vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_E_w4ehq0K");o<<in; o.close();freopen("IN_TEMP_E_w4ehq0K","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_E_w4ehq0K","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_E_w4ehq0K");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
#else
int main(){fakemain();}
#endif
/*
*o* Sample Input 1:
3 5
1 2 3
*o* Sample Output 1:
6
*o* Sample Input 2:
12 10
1 1 10 10 10 10 10 10 9 10 10 10
*o* Sample Output 2:
92
*o* Sample Input 3:
7 2
2 3 6 4 5 7 1
*o* Sample Output 3:
17
*o* Sample Input 4:
8 4
1 3 4 5 5 3 4 1
*o* Sample Output 4:
23
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/