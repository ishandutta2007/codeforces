import math
n,k=map(int,input().split())
print(math.ceil(2*n/k)+math.ceil(5*n/k)+math.ceil(8*n/k))