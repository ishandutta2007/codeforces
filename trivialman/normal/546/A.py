k, n, w = list(map(int, input().split()))
tot = k*(w+1)*w//2
if(tot<n):
    print(0)
else:
    print(tot-n)