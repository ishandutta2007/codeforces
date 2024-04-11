mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        S = input().rstrip('\n')
        st = []
        for s in S:
            if s == "A":
                st.append(s)
            else:
                if st:
                    if st[-1] == "A":
                        st.pop()
                    else:
                        st.append("B")
                else:
                    st.append("B")
        st2 = []
        for s in st:
            if s == "A":
                st2.append("A")
            else:
                if st2:
                    if st2[-1] == "B":
                        st2.pop()
                    else:
                        st2.append("B")
                else:
                    st2.append(s)
        print(len(st2))


if __name__ == '__main__':
    main()