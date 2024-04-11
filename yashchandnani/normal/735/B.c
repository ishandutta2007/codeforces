#include<stdio.h>
void merge(long int a[],long int start,long int pivot,long int end){
    long int x = pivot+1,j=0,l=end-start,y=start;
    long int b[l+1];
    while((start!=pivot+1)&&(x!=end+1)){
        if(a[start]>a[x]){
            b[j] = a[start];
            start++;
            j++;
        }
        else{
            b[j] = a[x];
            x++;
            j++;
        }

    }
    if(start==pivot+1){
        while(j<=l){
            b[j]=a[x];
            j++;
            x++;
        }

    }
    else{
        while(j<=l){
            b[j]=a[start];
            j++;
            start++;
        }

    }
    for (int i = 0; i <=l; i++)
    {
        a[y+i] = b[i];       
    }
    
    return;

}
void sort(long int a[],long int start,long int end){
    if(start==end) return;
    long int pivot = start + end ;
    pivot = pivot /2 ;
    sort(a,start,pivot);
    sort(a,pivot+1,end);
    merge(a,start,pivot,end);
    return;
}
int main(){
    long int n,n1,n2;
    double  avg = 0 ;
    scanf("%ld%ld%ld",&n,&n1,&n2);
    long int a[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%ld",&a[i]);
    }
    sort(a,0,n-1);
    if(n1>n2){
        for (int i = 0; i < n2; ++i)
        {
            avg = avg + a[i]*(1.0)/n2 ;
       
        }
        for (int i = n2; i < n1+n2; ++i)
        {
            avg = avg + a[i]*(1.0)/n1 ;
            
        }
    }
    else{
        for (int i = 0; i < n1; ++i)
        {
            avg = avg + a[i]*(1.0)/n1 ;
    
        }
        for (int i = n1; i < n1+n2; ++i)
        {
            avg = avg + a[i]*(1.0)/n2 ;
            
        }

    }
    printf("%lf\n",avg );

}