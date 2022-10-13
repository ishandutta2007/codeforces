#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
vector<pair<pair<int,int>,int>> ans;
void print(int i,int j,int x){
    ans.push_back({{i+1,j+1},x});
}
void solve(){
    int n; cin >> n;
    int sum = 0;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    if(sum%n!=0){
        cout << -1 << endl;
        return;
    }
    else{
        sum/=n;
        ans.clear();
        for(int i=0;i<n-1;i++){
            int num = a[i]/(i+1);
            print(i,i+1,num);
            a[i]-=num*(i+1);
            a[i+1]+=num*(i+1);
        }
        for(int i=n-1;i>=2;i--){
            if(a[i]>sum){
                int num = min(a[i]/(i+1),(a[i]-sum+i)/(i+1));
                if(num!=0) print(i,0,num);
                a[i]-=num*(i+1);
                a[0]+=num*(i+1);
                
                if(a[i]<sum){
                    print(0,i,sum-a[i]);
                    a[0]-=(sum-a[i]);
                    a[i] = sum;
                }
                else if(a[i]>sum){
                    print(0,i,i+1-a[i]);
                    a[0]-=(i+1-a[i]);
                    a[i] = i+1;
                    print(i,0,1);
                    a[i] = 0;
                    a[0]+=i+1;
                    print(0,i,sum);
                    a[0]-=sum;
                    a[i]+=sum;
                }
            }
            else if(a[i]<sum){
                print(0,i,sum-a[i]);
                a[0]-=(sum-a[i]);
                a[i] = sum;
            }
        }
        if(n>2){
            if(a[1]<sum){
                print(0,1,sum-a[1]);
                a[0]-=(sum-a[1]);
                a[1] = sum;
            }
            else if(a[1]>sum){
                    int num = (a[1]-sum+1)/2;
                    print(1,0,num);
                    a[1]-=(num*2);
                    a[0]+=num*2;
                    if(a[1]<sum){
                        print(0,1,sum-a[1]);
                        a[0] -=(sum-a[1]);
                        a[1] = sum;
                    }
            }
        }
        else if(n==2){
            if(a[1]<sum){
                print(0,1,sum-a[1]);
                a[0]-=(sum-a[1]);
                a[1] = sum;
            }
            else if(a[1]>sum){
                int num = (a[1]-sum+1)/2;
                print(1,0,num);
                a[1]-=(num*2);
                a[0]+=num*2;
                    if(a[1]<sum){
                        print(0,1,sum-a[1]);
                        a[0] -=(sum-a[1]);
                        a[1] = sum;
                    }
                
            }
        }
        cout << ans.size() << endl;
        for(auto &it : ans){
            cout << it.first.first << " " << it.first.second << " " << it.second << endl;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}