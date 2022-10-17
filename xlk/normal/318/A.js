var l = readline().split(' ');
print((2 * l[1] - 2 + (1 - l[0] % 2) * (l[1] * 2 - 1 > l[0])) % l[0] + 1)