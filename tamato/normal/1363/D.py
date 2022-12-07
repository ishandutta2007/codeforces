mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(i_list):
        tmp = []
        for i in i_list:
            tmp.extend(S[i-1])
        print("? " + str(len(tmp)) + " " + " ".join(map(str, tmp)))
        sys.stdout.flush()

    def ask2(i_list):
        print("? " + str(len(i_list)) + " "  + " ".join(map(str, i_list)))
        sys.stdout.flush()

    for _ in range(int(input())):
        N, K = map(int, input().split())
        S = []
        for _ in range(K):
            line = list(map(int, input().split()))
            S.append(line[1:])
        ask(list(range(1, K+1)))
        M = int(input())
        if M == -1:
            exit()

        L = 1
        R = K
        mid = (L+R) // 2
        for _ in range(10):
            if R == L:
                break
            ask(list(range(L, mid+1)))
            m = int(input())
            if m == -1:
                exit()
            if m == M:
                R = mid
            else:
                L = mid + 1
            mid = (R+L) // 2
        B = [1] * (N+1)
        for i in S[L-1]:
            B[i] = 0
        i_list = []
        for i in range(1, N+1):
            if B[i]:
                i_list.append(i)
        ask2(i_list)
        m2 = int(input())
        if m2 == -1:
            exit()
        ans = []
        for i in range(1, K+1):
            if i == L:
                ans.append(m2)
            else:
                ans.append(max(M, m2))
        print("! " + " ".join(map(str, ans)))
        sys.stdout.flush()
        verdict = input().rstrip('\n')
        if verdict == "Correct":
            continue
        elif verdict == "Incorrect":
            exit()


if __name__ == '__main__':
    main()