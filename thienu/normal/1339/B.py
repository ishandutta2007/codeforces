import sys

def calculate_case():
    n = int(input())
    a = list(map(int, input().split(" ")))
    a.sort()
    out = []
    if n % 2 != 0:
        out.append(str(a[n // 2]))
    left = (n - 2) // 2
    right = (n + 1) // 2
    while left >= 0:
        out.append(str(a[left]))
        out.append(str(a[right]))
        left -= 1
        right += 1
    sys.stdout.write(" ".join(out) + "\n")



if __name__ == "__main__":
    test_cases = int(input())
    for i in range(1, test_cases + 1):
        calculate_case()