#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int p,k;
    cin>>p>>k;
    vector <int> v;
    int c=1;
    while(p!=0)
    {
        if(c==1){
        v.push_back(p%k);
        p-=(p%k);
        }
        else{
                if(p%k!=0){
        v.push_back(k-p%k);
        p+=k;p-=(p%k);
                }
                else
                {
                    v.push_back(0);
                }
        }
        c*=(-1);
        p/=k;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i) cout<<v[i]<<" ";
    return 0;
}