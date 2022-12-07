mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    for _ in range(int(input())):
        S = input().rstrip('\n')
        C = Counter(S)
        if len(C) == 1:
            print(S)
        elif len(C) == 2:
            s_list = sorted(list(C.keys()))
            if ord(s_list[1]) - ord(s_list[0]) == 1:
                print("No answer")
            else:
                print(S)
        elif len(C) == 3:
            s_list = sorted(list(C.keys()))
            s0, s1, s2 = s_list
            if ord(s1) - ord(s0) == 1 and ord(s2) - ord(s1) == 1:
                print("No answer")
            else:
                if ord(s1) - ord(s0) != 1:
                    print("".join([s1 * C[s1], s0 * C[s0], s2 * C[s2]]))
                else:
                    print("".join([s1 * C[s1], s2 * C[s2], s0 * C[s0]]))
        else:
            ans = []
            L = len(C)
            s_list = sorted(list(C.keys()))
            for i in range(L):
                if i*2+1 >= L:
                    break
                ans.append(s_list[i*2+1] * C[s_list[i*2+1]])
            for i in range(L):
                if i*2 >= L:
                    break
                ans.append(s_list[i*2] * C[s_list[i*2]])
            print("".join(ans))


if __name__ == '__main__':
    main()