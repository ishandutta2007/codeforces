n = input()
cubes = []
for i in xrange(n):
    cubes.append(map(int, raw_input().split()))

yes = [False] * 1111

for i in xrange(len(cubes)):
    for j in cubes[i]:
        yes[j] = True
    for j in xrange(len(cubes)):
        if i == j:
            continue
        for k in cubes[i]:
            for l in cubes[j]:
                yes[k * 10 + l] = True
        for k in xrange(len(cubes)):
            if i == k or j == k:
                continue
            for X in cubes[i]:
                for Y in cubes[j]:
                    for Z in cubes[k]:
                        yes[X * 100 + Y * 10 + Z] = True

for i in xrange(1, 1111):
    if yes[i] == False:
        print i - 1
        break