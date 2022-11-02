def f():
    n = int(input())
    k = n // 7
    while k >= 0:
        x = n - 7 * k
        if x % 4 == 0:
            print('4'*(x//4)+'7'*k)
            return
        k -= 1
    print('-1')
f()