def main():
    import sys
    input = sys.stdin.readline

    A = ['?']
    for i in range(1, 101):
        A.append((1 << 7) * i)
    print(*A, flush=True)
    ans1 = int(input()) % (1<<7)
    A = ['?']
    for i in range(100):
        A.append(i)
    print(*A, flush=True)
    ans2 = (int(input()) >> 7) << 7

    print('!', ans1 + ans2, flush=True)
    exit()


if __name__ == '__main__':
    main()