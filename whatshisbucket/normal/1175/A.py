t=int(input())
def base(n,k):
    if n==0:
        return 0
    return n%k+base(n//k,k)+1
for u in range(t):
    n,k=map(int,input().split())
    print(base(n,k)-1)