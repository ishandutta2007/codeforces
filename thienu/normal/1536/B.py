import string
import itertools

def solve():
    n = int(input())
    s = input()
    alphabet = list(string.ascii_lowercase)
    l = 1
    while True:
        for t in itertools.product(*(alphabet for _ in range(l))):
            if "".join(t) not in s:
                print("".join(t))
                return
        l += 1

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()