mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(s, a):
        print(s, a)
        sys.stdout.flush()

    N = int(input())
    is_prime = [True] * (N+1)
    is_prime[0] = False
    is_prime[1] = False
    P = []
    for i in range(2, N+1):
        if is_prime[i]:
            P.append(i)
            for j in range(2, N+1):
                if i*j > N:
                    break
                is_prime[i*j] = False

    NP = len(P)
    flg = [True] * (N+1)
    remain = N
    mode = 0
    ans = []
    for i in range((NP-1) // 100 + 1):
        if mode == 0:
            for j in range(100):
                if i*100+j >= len(P):
                    break
                p = P[i*100+j]
                ask("B", p)
                for d in range(1, N+1):
                    if p*d > N:
                        break
                    if flg[p*d]:
                        remain -= 1
                    flg[p*d] = False
                _ = int(input())
            ask("A", 1)
            a = int(input())
            if a != remain:
                for j in range(100):
                    if i * 100 + j >= len(P):
                        break
                    p = P[i*100+j]
                    ask("A", p)
                    a = int(input())
                    if a:
                        ans.append(p)
                mode = 1
        else:
            for j in range(100):
                if i * 100 + j >= len(P):
                    break
                p = P[i * 100 + j]
                ask("B", p)
                a = int(input())
                b = 0
                for d in range(1, N+1):
                    if p*d > N:
                        break
                    if flg[p*d]:
                        b += 1
                        flg[p*d] = False
                if a != b:
                    ans.append(p)

    if not ans:
        ask("C", 1)
        exit()

    while len(ans) < 6:
        ans.append(1)
    ans.sort(reverse=True)
    ANS = []
    seen = [False] * (N+1)
    for i in range(1, 18):
        tmp_i = ans[0] ** i
        if tmp_i > N:
            break
        for j in range(1, 18):
            tmp_j = tmp_i * (ans[1] ** j)
            if tmp_j > N:
                break
            for k in range(1, 18):
                tmp_k = tmp_j * (ans[2] ** k)
                if tmp_k > N:
                    break
                for l in range(1, 18):
                    tmp_l = tmp_k * (ans[3] ** l)
                    if tmp_l > N:
                        break
                    for m in range(1, 18):
                        tmp_m = tmp_l * (ans[4] ** m)
                        if tmp_m > N:
                            break
                        for n in range(1, 18):
                            tmp_n = tmp_m * (ans[5]**n)
                            if tmp_n > N:
                                break
                            if not seen[tmp_n]:
                                ask("A", tmp_n)
                                a = int(input())
                                if a:
                                    ANS.append(tmp_n)
                                seen[tmp_n] = True
    ANS.sort()
    ask("C", ANS[-1])


if __name__ == '__main__':
    main()