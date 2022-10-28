n=int(input())
h1=list(map(int,input().split()))
h2=list(map(int,input().split()))
dp1=[0]
dp2=[0]
for i in range(n):
    dp1.append(max(dp1[-1],dp2[-1]+h1[i]))
    dp2.append(max(dp2[-1],dp1[-2]+h2[i]))
print(max(dp1[-1],dp2[-1]))