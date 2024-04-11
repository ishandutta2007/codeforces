n=[int(k) for k in input().split(" ")][0]

def tri(n):
    return n*(n+1)//2


print(tri(n)+2*tri(n-1)+tri(n-2))