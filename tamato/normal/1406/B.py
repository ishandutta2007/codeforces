mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        pos = []
        neg = []
        for a in A:
            if a < 0:
                neg.append(a)
            else:
                pos.append(a)
        pos.sort()
        neg.sort(reverse=True)

        ans = -float("inf")
        for ne in range(6):
            po = 5 - ne
            tmp = 1
            if ne & 1:
                if len(pos) >= po and len(neg) >= ne:
                    for i in range(po):
                        tmp *= pos[i]
                    for i in range(ne):
                        tmp *= neg[i]
                    ans = max(ans, tmp)
            else:
                if len(pos) >= po and len(neg) >= ne:
                    for i in range(po):
                        tmp *= pos[-i-1]
                    for i in range(ne):
                        tmp *= neg[-i-1]
                    ans = max(ans, tmp)
        print(ans)


if __name__ == '__main__':
    main()