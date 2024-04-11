s = raw_input()
print min(max(map(len, s.split(c))) for c in set(s)) + 1