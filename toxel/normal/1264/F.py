def mult(a, b):
    c = [[0, 0], [0, 0]]
    global moder
    for k in range(0, 2):
        for i in range(0, 2):
            for j in range(0, 2):
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % moder
    return c


def powermod(a, exp):
    ret = [[1, 0], [0, 1]]
    while exp > 0:
        if exp % 2 == 1:
            ret = mult(ret, a)
        a = mult(a, a)
        exp >>= 1
    return ret


def eucinv(a, mod):
    b, s, t = mod, 1, 0
    while b:
        a, b, q = b, a % b, a // b
        s, t = t, s - t * q
    return s + mod if s < 0 else s


if __name__ == '__main__':
    n, a, d = map(int, input().split())
    moder = 10 ** 18
    period = 12 * 10 ** 9
    fn_1 = powermod([[0, 1], [1, 1]], period + 1)[0][1]
    t = (fn_1 - 1) // 8 // 10 ** 9
    invt = eucinv(t % 10 ** 6, 10 ** 6)
    e = 125 * (d * invt % 10 ** 6)
    e *= period
    b = 125 * (a * invt % 10 ** 6)
    b *= period
    b += 1
    print(b, e)