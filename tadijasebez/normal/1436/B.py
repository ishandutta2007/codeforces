t = int(input())
for _ in range(t):
    n = int(input())
    for i in range(n):
        for j in range(n):
            print("1 " if i == j or (j+1) % n == i else "0 ", end="" if j != n-1 else "\n")