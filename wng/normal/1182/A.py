n=[int(k) for k in input().split(" ")][0]
if n%2:
    print(0)
else:
    print(1<<(n//2))