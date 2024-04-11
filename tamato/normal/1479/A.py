mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(i):
        print("?", i)
        sys.stdout.flush()
        return int(input())

    """
    A = list(map(int, input().split()))

    def ask(i):
        return A[i-1]
    """

    N = int(input())
    l = 0
    r = N+1
    m = (l+r)//2
    al = ar = N+1
    am = ask(m)
    while m-l > 1 or r-m > 1:
        if m-l >= r-m:
            m_new = (l+m) // 2
            a_new = ask(m_new)
            if a_new < min(al, am):
                r = m
                ar = am
                m = m_new
                am = a_new
            else:
                l = m_new
                al = a_new
        else:
            m_new = (m+r) // 2
            a_new = ask(m_new)
            if a_new < min(am, ar):
                l = m
                al = am
                m = m_new
                am = a_new
            else:
                r = m_new
                ar = a_new
    print("!", m)
    sys.stdout.flush()


if __name__ == '__main__':
    main()