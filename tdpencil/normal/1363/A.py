import math

def ni():
    return int(input())
def vals():
    return list(map(int, input().split()))
def nextLine():
    return input()

t = ni()
while t > 0:
    t -= 1
    cnt = [0, 0]

    n, x = vals()
    a = vals()

    for i in a:
        cnt[i & 1] += 1

    if cnt[0] == 0:
        if x % 2:
            print("YES")
        else:
            print("NO")
    elif cnt[1] == 0:
        print("NO")
    else:
        if cnt[1] % 2 == 1:
            print("YES")
        else:
            if x == n:
                print("NO")
            else:
                print("YES")