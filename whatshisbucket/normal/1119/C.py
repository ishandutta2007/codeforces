n,m=map(int,input().split())
A=[0]*n
for i in range(n):
    A[i]=list(map(int,input().split()))
B=[0]*n
for i in range(n):
    B[i]=list(map(int,input().split()))
Arows=[sum(A[i])%2 for i in range(n)]
Acols=[sum(A[j][i] for j in range(n))%2 for i in range(m)]
Brows=[sum(B[i])%2 for i in range(n)]
Bcols=[sum(B[j][i] for j in range(n))%2 for i in range(m)]
if Arows==Brows and Acols==Bcols:
    print("Yes")
else:
    print("No")