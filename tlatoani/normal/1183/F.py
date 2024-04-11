answer = []
for _ in range(int(input())):
    input()
    l = sorted(map(int, input().split()))
    other = 0
    if l[-1] % 30 == 0 and len(set(l) & {l[-1] // 2, l[-1] // 3, l[-1] // 5}) == 3:
        other = (31 * l[-1]) // 30
    while len(l) >= 2 and l[-1] % l[-2] == 0:
        del l[-2]
    while len(l) >= 3 and 0 in (l[-1] % l[-3], l[-2] % l[-3]):
        del l[-3]
    answer.append(str(max(other, sum(l[-3:]))))
print("\n".join(answer))