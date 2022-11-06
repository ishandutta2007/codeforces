#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int p2[1000][1000];
int p5[1000][1000];

void print2(int x,int y){
        if (x+y==0) return;
        if (p2[x][y]) {print2(x-1,y); printf("%c",'D');} else {print2(x,y-1); printf("%c",'R');}
    }
void print5(int x,int y){
        if (x+y==0) return;
        if (p5[x][y]) {print5(x-1,y); printf("%c",'D');} else {print5(x,y-1); printf("%c",'R');}
    }
    
int main(){
    int iszerothere=0;
    int d5[1000]={0};
    int d2[1000]={0};
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int u;
            scanf("%d",&u);
            int n2=0;
            int n5=0;
            if (u>0) {
            while (u%2==0) {
                u/=2;
                n2++;
            }
            while (u%5==0)  {
                u/=5;
                n5++;
            }}
            else {n2=100000;n5=100000;iszerothere=i*n+j+1;}
            
            if (i==0){
                if (j==0){
                    d2[j]=n2;
                    d5[j]=n5;
                    p2[i][j]=0;
                    p5[i][j]=0;
                }
                else { 
                    d2[j]=n2+d2[j-1];
                    d5[j]=n5+d5[j-1];
                    p2[i][j]=0; 
                    p5[i][j]=0;
                }
            }
            else{
                if (j==0){
                    d2[j]=n2+d2[j];
                    d5[j]=n5+d5[j];
                    p2[i][j]=1;
                    p5[i][j]=1;
                }
                else { 
                    if (d2[j-1]<d2[j]) {
                        p2[i][j]=0;
                        d2[j]=d2[j-1]+n2;
                    } 
                    else {
                        p2[i][j]=1;
                        d2[j]+=n2;
                    }
                    
                    if (d5[j-1]<d5[j]) {
                        p5[i][j]=0;
                        d5[j]=d5[j-1]+n5;
                    } 
                    else {
                        p5[i][j]=1;
                        d5[j]+=n5;
                    }
                }
            }
        }
    }
    if (!iszerothere or min(d2[n-1],d5[n-1])<=1) {
    printf("%d\n",min(d2[n-1],d5[n-1]));
    if (d2[n-1]<d5[n-1]) print2(n-1,n-1);
    else print5(n-1,n-1);}
    else {
        printf("%d\n",1);
        int j=(iszerothere-1)%n;
        int i = (iszerothere - 1 - j)/n;
        for (int k=0;k<i;k++) printf("%c",'D');
        for (int k=1;k<n;k++) printf("%c",'R');
        for (int k=i+1;k<n;k++) printf("%c",'D');
    }
}