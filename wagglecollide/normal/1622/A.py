import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    l1, l2, l3 = map(int, input().split())
    n = [l1, l2, l3]
    n.sort()
    ls = n[0] + n[1] + n[2]
    if ls % 2 == 1:
        print("NO")
        continue
    ls //= 2
    if n[0] == n[1] or n[1] == n[2]:
        if ls <= n[0] or ls <= n[1]:
            print("NO")
            continue
        print("YES")
        continue
    if n[0] + n[1] == ls:
        print("YES")
        continue
    if n[1] + n[2] == ls:
        print("YES")
        continue
    if n[0] + n[2] == ls:
        print("YES")
        continue
    print("NO")