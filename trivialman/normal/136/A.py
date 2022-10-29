n = int(input())
a = list(map(int, input().split()))
b = [0]*101
for i in range(n):
    b[a[i]-1]=str(i+1)
print(' '.join(b[:n]))