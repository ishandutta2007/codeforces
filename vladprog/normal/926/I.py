n=int(input())
a=[]
for i in range(n):
    h,m=map(int,input().split(':'))
    a+=[h*60+m]
a.sort()
a+=[a[0]+24*60]
ans=-1
for i in range(n):
    ans=max(ans,a[i+1]-a[i]-1)
h,m=ans//60,ans%60
if h<10:
    print(0,end='')
print(h,end=':')
if m<10:
    print(0,end='')
print(m,end='')