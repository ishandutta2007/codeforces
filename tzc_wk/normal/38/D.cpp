#include <iostream>
using namespace std;
const int N=115;
struct node{
    double x1,x2,y1,y2;
    double x,y;
    double m;
    node(int a,int b,int c,int d){
        x1 = a; y1 = b; x2 = c; y2 = d;
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        x=(x1+x2)/2;y=(y1+y2)/2;
        m=y2-y1;m=m*m*m;
    }
    node(){};
}b[N];
int n;
double x1,x2,y1,y2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;
        b[i]=node(x1,y1,x2,y2);
    }
    for(int i=2;i<=n;i++){
        double x=b[i].x,y=b[i].y,m=b[i].m;
        for(int j=i-1;j>=1;j--){
            if(x<b[j].x1||x>b[j].x2||y<b[j].y1||y>b[j].y2){
                cout<<i-1<<endl;
                return 0;
            }
            x+=(b[j].x-x)*b[j].m/(m+b[j].m);
            y+=(b[j].y-y)*b[j].m/(m+b[j].m);
            m=m+b[j].m;
        }
    }
    cout<<n<<endl;
    return 0;
}