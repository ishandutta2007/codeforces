n, m = map(int, input().split())
a = input().split()
b = input().split()
q = int(input())
while q:
    q -= 1
    n = int(input()) - 1
    print(a[n%len(a)] + b[n%len(b)])