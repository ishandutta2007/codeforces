INF = 10**40

def gcd_ex(A, B):
    if A == 0:
        return B, 0, 1
    g, a1, b1 = gcd_ex(B % A, A)
    a = b1 - (B // A) * a1
    b = a1
    return g, a, b

def round_down(a, b):
    s = (a < 0) != (b < 0)
    a = abs(a)
    b = abs(b)
    if not s:
        return a // b
    return -((a + b - 1) // b)

def round_up(a, b):
    s = (a < 0) != (b < 0)
    a = abs(a)
    b = abs(b)
    if not s:
        return (a + b - 1) // b
    return -(a // b)

def solve():
    x, y, p, q = map(int, input().split())

    A = q
    B = -p
    C = p * y - q * x

    g, a0, b0 = gcd_ex(A, -B)
    b0 *= -1

    if C % g != 0:
        print(-1)
        return
    a0 *= C // g
    b0 *= C // g

    k_up1 = 0
    if B == 0:
        if -a0 > 0:
            print(-1)
            return
        k_up1 = INF
    else:
        k_up1 = round_down(-a0, B // g)

    k_down2 = 0
    k_up2 = 0
    if A + B == 0:
        if b0 - a0 < 0:
            print(-1)
            return
        k_down2 = -INF
        k_up2 = INF
    elif A + B > 0:
        k_down2 = -INF
        k_up2 = round_down(b0 - a0, (A + B) // g)
    else:
        k_down2 = round_up(b0 - a0, (A + B) // g)
        k_up2 = INF

    k_down = k_down2
    k_up = min(k_up1, k_up2)
    if k_down > k_up:
        print(-1)
        return

    if k_up == INF:
        raise Exception
    b = b0 - (A // g) * k_up

    print(b)

def main():
    t = int(input())
    for i in range(t):
        solve()

main()