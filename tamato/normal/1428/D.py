mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    check = 0
    for a in A:
        if a == 2:
            check += 1
        elif a == 1:
            if check > 0:
                check -= 1
    if check > 0:
        print(-1)
        exit()
    for a in reversed(A):
        if a == 3:
            print(-1)
            exit()
        elif a == 1 or a == 2:
            break

    ans = []
    h = 0
    flg = 1
    if 3 in A:
        ww = -1
        for i in range(N-1, -1, -1):
            a = A[i]
            if a == 2:
                ww = i
                flg = 0
                break
            elif a == 1 and ww == -1:
                ww = i
            elif a == 3:
                if ww == -1:
                    print(-1)
                    exit()
                else:
                    break
        prev = -1
        for i, a in enumerate(A):
            if a == 3:
                if prev != -1:
                    ans.append((h, prev))
                    ans.append((h, i))
                    h += 1
                prev = i
        ans.append((h, prev))
        ans.append((h, ww))
        ans.append((h+1, ww))
        h += 1
        hh = h
        h += 1
    else:
        flg = 0
        ww = -1
        hh = -1

    st = []
    for i, a in enumerate(A):
        if a == 2:
            if i != ww:
                ans.append((h, i))
                st.append((h, i))
                h += 1
            else:
                st.append((hh, i))
        elif a == 1:
            if st:
                if flg and i == ww:
                    print(-1)
                    exit()
                hhh, www = st.pop()
                ans.append((hhh, i))
            else:
                if i != ww:
                    ans.append((h, i))
                    h += 1
                else:
                    pass
    print(len(ans))
    for h, w in ans:
        print(h+1, w+1)


if __name__ == '__main__':
    main()