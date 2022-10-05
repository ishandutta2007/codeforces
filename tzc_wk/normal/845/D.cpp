#include <iostream>
using namespace std;
const int MAXN=300000+10;
int stack[MAXN],curv=0,overtake=0,limit=INT_MAX,ans=0,ff=0,top=0;
int main(){
    int n;cin>>n;
    while(n--){
        int t;cin>>t;
        if(t==1){
            int s;cin>>s;curv=s;
            while(top&&stack[top]<curv){
                ans++;top--;
            }
        }
		else if(t==2){
            if(overtake&&ff){
                ans+=ff;ff=0;
                overtake=0;
            }
        }
		else if(t==3){
            int s;cin>>s;limit=s;
            if(curv>limit)	ans++;
            else	stack[++top]=limit;
        }
		else if(t==4)	overtake=0,ff=0;
		else if(t==5){
            limit=INT_MAX;
            if(curv>limit)	ans++;
            else	stack[++top]=limit;
        }
		else if(t==6)	overtake=1,ff+=1;
    }
    cout<<ans<<endl;
}