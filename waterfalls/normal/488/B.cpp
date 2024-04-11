#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[4];
int b[4];

int mean() { return a[0]+a[1]+a[2]+a[3]; }
int median() { return 2*(a[1]+a[2]); }
int range() { return 4*(a[3]-a[0]); }

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) a[i] = b[i];
    sort(b,b+n);
    sort(a,a+n);
    if (n==4) {
        if (mean()==median() && mean()==range()) printf("YES\n");
        else printf("NO\n");
    } else if (n==3) {
        bool flag = 1;
        for (int add=1;add<=1000000 && flag;add++) {
            for (int i=0;i<n;i++) a[i] = b[i];
            a[3] = add;
            sort(a,a+4);
            if (mean()==median() && mean()==range()) {
                printf("YES\n%d\n",add);
                flag = 0;
            }
        }
        if (flag) printf("NO\n");
    } else if (n==2) {
        if (a[0]==a[1]) printf("YES\n%d\n%d\n",3*a[0],3*a[0]);
        else {
            bool flag = 1;
            for (int add=a[1];add<=1000000 && flag;add++) {
                for (int i=0;i<n;i++) a[i] = b[i];
                a[2] = add;
                a[3] = 4*(add-a[0])-a[0]-a[1]-add;
                if (a[3]>add || a[3]<a[0]) continue;
                sort(a,a+4);
                if (mean()==median() && mean()==range()) {
                    printf("YES\n%d\n%d\n",add,4*(add-b[0])-b[0]-b[1]-add);
                    flag = 0;
                }
            }
            for (int add=1;add<=a[0] && flag;add++) {
                for (int i=0;i<n;i++) a[i] = b[i];
                a[2] = add;
                a[3] = (5*add+a[0]+a[1])/3;
                if (a[3]<a[1]) continue;
                sort(a,a+4);
                if (mean()==median() && mean()==range()) {
                    printf("YES\n%d\n%d\n",add,(5*add+b[0]+b[1])/3);
                    flag = 0;
                }
            }
            for (int add1=1;add1<=a[1] && flag;add1++) {
                for (int add2=add1;add2<=a[1] && flag;add2++) {
                    for (int i=0;i<n;i++) a[i] = b[i];
                    a[2] = add1;
                    a[3] = add2;
                    sort(a,a+4);
                    if (mean()==median() && mean()==range()) {
                        printf("YES\n%d\n%d\n",add1,add2);
                        flag = 0;
                    }
                }
            }
            if (flag) printf("NO\n");
        }
    } else if (n==1) printf("YES\n%d\n%d\n%d",2*a[0],2*a[0],3*a[0]);
    else printf("YES\n1\n1\n3\n3\n");

    return 0;
}