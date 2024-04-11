maxn = 10000 + 10
prime = []
p = [False for i in range(maxn)]

def sieve():
    for i in range(2, maxn):
        if not p[i]: prime.append(i)
        for j in range(maxn):
            if i * prime[j] >= maxn: break
            p[i * prime[j]] = True
            if i % prime[j] == 0: break


def main():
    sieve()
    n = int(input())
    if n == 2:
        print("-1")
        exit(0)
    # for i in prime: print(i, end=' ')
    for i in range(n):
        a = 1
        for j in range(n):
            if j == i: continue
            a *= prime[j]
        print(a)


if __name__ == '__main__':
    main()