l = [int(x) for x in raw_input().split()]
l = sorted(l)
print "{} {} {}".format(l[3] - l[0], l[3] - l[1], l[3] - l[2])