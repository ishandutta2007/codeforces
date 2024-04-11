#include<iostream>
#include<map>
#include<set>
using namespace std;
struct K{int a,b;};
map<int,int> m1,m2;
long long ans;
map<K,int> m3;
bool operator<(K l,K m)
{if(l.a!=m.a) return l.a<m.a;
else return l.b<m.b;
}
main()
{long long n,x,y;

K q;
cin>>n;
for (int i=0; i<n; i++)
{cin>>x>>y;
q.a=x; q.b=y;
if(m1[x]!=0) ans+=m1[x]; if(m2[y]!=0)ans+=m2[y];
if(m3[q]>0) {ans-=m3[q]; }
//cout<<ans<<" "<<m3[q]<<" "<<m1[x]<<" "<<m2[y]<<endl;
m3[q]++;
m1[x]++; m2[y]++;
}
cout<<ans<<endl;
}