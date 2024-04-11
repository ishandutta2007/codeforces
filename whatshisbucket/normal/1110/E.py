n=int(input())
c=list(map(int,input().split()))
t=list(map(int,input().split()))
cdiffs=[c[i+1]-c[i] for i in range(n-1)]
tdiffs=[t[i+1]-t[i] for i in range(n-1)]
if sorted(cdiffs)==sorted(tdiffs) and t[0]==c[0]:
    print("Yes")
else:
    print("No")