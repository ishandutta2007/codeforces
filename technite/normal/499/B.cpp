#include<bits/stdc++.h>
using namespace std;
 
#define for(i,n) for(int i=0;i<n;i++)
 
using namespace std;
string a,b;
vector<string> s1,s2;
 
int main()
 
{    int n,m;
    cin >>n>>m;
    
    
    
    
    while (m--){
        cin>>a;
        cin>>b;
        //cout<<a<<" "<<b<<endl;
        s1.push_back(a);
        s2.push_back(b);
    }
    
    
    
    while(n--){
        cin>>a;
        vector<string>::iterator it=find(s1.begin(),s1.end(),a); 
        
        //cout<<a<<endl;
        int index;
        
        
        index = std::distance(s1.begin(), it);
            
         b=s2[index];   
        if(a.length()<=b.length()){
            cout<<a<<" ";
        }
        else{
            cout<<b<<" ";
        }
    }
    
 
    return 0;
}