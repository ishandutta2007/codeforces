#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
using namespace std;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);

}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n,m,k,p,n1,n2,n3,t1,t2,t3;
  m=0;
 //int ans=200000000;

 //cin >> n>> m >> k;
 cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
 /*
std::vector<std::vector<int>> ch(n+1);
std::vector<int> par(n+1);
std::vector<std::vector<int>> nb(n+1);
std::vector<std::vector<int>> lvl(n+1);
std::vector<int> v_lvl(n+1,0);
m=1;
lvl[1].push_back(1);
v_lvl[1]=1;
for(int i=1;i<n;i++){
    int u,v;
    cin >>u>>v;
    nb[u].push_back(v);
    nb[v].push_back(u);
    //xp;
}
int l=2;

while(m<n){
    for(int k=0; k<lvl[l-1].size(); k++){
        int v=lvl[l-1][k];
        for(int h=0; h<nb[v].size();h++){
            if(v_lvl[nb[v][h]]==0){
                v_lvl[nb[v][h]]=l;
                lvl[l].push_back(nb[v][h]);
                m++;
                ch[v].push_back(nb[v][h]);
                par[nb[v][h]]=v;
            }
        }
    }
    l++;
}
l--;*//*
std::vector<long long> lsize(l+1);
for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();*/

/*
 for(int i=0; i<n; i++){
     long long x;
     cin>>x;

 }*/
 int t=0;
 int wa=0, dr=0, ir=0;
 std::deque<int> wash;
 std::deque<int> dry;
 std::deque<int> iron;
 while(k>0){
	 if((wa<n1)&&(dr<n2)&&(ir<n3)){
		 wa++;
		 dr++;
		 ir++;
		 k--;
		 wash.push_back(t+t1);
		 dry.push_back(t+t2);
		 iron.push_back(t+t3);
		 continue;
	 }
	 int w=999999999;
	 if(wash.size()>0) w=wash.front();
	 int d=999999999;
	 if(dry.size()>0) d=dry.front();
	 int i=999999999;
	 if(iron.size()>0) i=iron.front();
	 int newt=min(w,min(d,i));
	 while((wash.size()>0)&&(wash.front()==newt)) {
		 wash.pop_front(); 
		 wa--;
	 }
	 while((dry.size()>0)&&(dry.front()==newt)) {
		 dry.pop_front();
		 dr--;
	 }
	 while((iron.size()>0)&&(iron.front()==newt)) {
		 iron.pop_front();
		 ir--;
	 }
	 t=newt;

 }
 cout<<(t+t1+t2+t3);
//cout<<ans;
  return 0;
}