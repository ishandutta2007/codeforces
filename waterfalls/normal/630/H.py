def combo(n,k):
 res = 1
 for i in range(n,n-k,-1): res*=i
 for i in range(k,0,-1): res//=i
 return res

n = int(input())
print(combo(n,5)*combo(n,5)*120)