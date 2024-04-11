def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    dic1 = {}
    dic2 = {}
    A1 = [0] * N
    for i, a in enumerate(A):
        A1[i] = a>>15
    for i in range(2**15):
        tmp = [0] * N
        for j, a in enumerate(A1):
            a ^= i
            tmp[j] = bin(a).count('1')
        t0 = tmp[0]
        for j in range(N):
            tmp[j] -= t0
        dic1[i] = tuple(tmp)

    A2 = [0] * N
    for i, a in enumerate(A):
        A2[i] = a % (2**15)
    for i in range(2 ** 15):
        tmp = [0] * N
        for j, a in enumerate(A2):
            a ^= i
            tmp[j] = -(bin(a).count('1'))
        t0 = tmp[0]
        for j in range(N):
            tmp[j] -= t0
        dic2[tuple(tmp)] = i

    for i in range(2**15):
        if dic1[i] in dic2:
            # ans = i*(2**15) + dic2[dic1[i]]
            # print([bin(a^ans).count('1') for a in A])
            print(i*(2**15) + dic2[dic1[i]])
            exit()
    print(-1)


if __name__ == '__main__':
    main()