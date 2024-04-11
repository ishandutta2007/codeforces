# d-decrease-the-sum-of-digits.yml

def dsum(x):
    res = 0
    while x:
        res += x % 10
        x //= 10
    return res

for _ in range(int(input())):
    n, s = map(int, input().split())
    # print(f'init: n={n}, s={s}')

    p = 1
    ans = 0
    csum = dsum(n)
    # its=10
    while csum > s:
        # print(f'n={n}')
        add = 10 * p - n % (10 * p)
        if add == 10 * p: add = 0
        ans += add
        n += add
        csum = dsum(n)
        p *= 10
        # print(f'n={n},p={p},csum={csum},add={add}')

        # its-=1
        # assert its

    print(ans)