#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  int n;
int ans=0;
  //cin >> a >> k;
int r[25];
for(int i=0;i<25;i++) r[i]=0;
//cin>>n;
for(int i=0; i<5;i++)
    for(int j=0;j<5;j++){
        int x;
        cin>>x;
        r[i*5+j]+=x;
        r[j*5+i]+=x;

    }

for(int a1=0;a1<5; a1++)
    for(int a2=0;a2<5; a2++)
        for(int a3=0;a3<5; a3++)
            for(int a4=0;a4<5; a4++)
                for(int a5=0;a5<5; a5++)
                {
                    std::vector<int> a;
                    a.push_back(a1);
                    a.push_back(a2);
                    a.push_back(a3);
                    a.push_back(a4);
                    a.push_back(a5);
                    std::sort(a.begin(), a.end());
                    bool f=false;
                    for(int j=0; j<4;j++) if(a[j]==a[j+1]) f=true;
                    if(f) continue;
                    int sum=r[a1*5+a2]+r[a2*5+a3]+2*r[a3*5+a4]+2*r[a4*5+a5];
                    if(sum>ans) ans=sum;
                }

  cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}