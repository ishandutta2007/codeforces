import array
def solve():
    n,ans,lv,c=int(input()),1,0,0
    a=array.array('i',map(int,input().split()))
    for i in range(1,n):
        if a[i]>a[i-1]:
            c+=1
        else:
            if lv==0:
                ans,lv=ans+1,c-1
            else:
                lv-=1
    print(ans)
T=int(input())
for Tid in range(T):
    solve()