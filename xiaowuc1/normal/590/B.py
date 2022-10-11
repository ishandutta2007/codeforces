### TEMPLATE BEGIN

from collections import defaultdict
from math import sqrt

def read_int():
    return int(raw_input())

def read_ints():
    return (int(x) for x in raw_input().split())

def read_int_list():
    return [int(x) for x in raw_input().split()]

def read_float():
    return float(raw_input())

def read_floats():
    return (float(x) for x in raw_input().split())

def read_float_list():
    return [float(x) for x in raw_input().split()]

def read_list():
    return [x for x in raw_input().split()]

def read_line():
    return raw_input()

### TEMPLATE END

class Circle(object):
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r

    def is_point_in(self, x, y):
        return dist(self.x, self.y, x, y) <= self.r

    def touches_other_circle(self, circle):
        return dist(self.x, self.y, circle.x, circle.y) <= self.r + circle.r

def dist(x1, y1, x2, y2):
    x = x1 - x2
    y = y1 - y2
    return sqrt(x**2 + y**2)

def find_min_radius(x, y, vx, vy, vmax):
    l = 0
    r = 1e3
    for ___ in xrange(100):
        m = (l+r)/2
        circle = Circle(m * vx, m * vy, m * vmax)
        if circle.is_point_in(x, y):
            r = m
        else:
            l = m
    return l

def solve():
    x1, y1, x2, y2 = read_floats()
    x2 -= x1
    y2 -= y1
    x1 = 0
    y1 = 0
    vmax, t = read_floats()
    vx, vy = read_floats()
    wx, wy = read_floats()
    # case 1
    # only need phase one of wind
    circle = Circle(t * vx, t * vy, t * vmax)
    if circle.is_point_in(x2, y2):
        print find_min_radius(x2, y2, vx, vy, vmax)
        return
    # case 2
    l = 0
    r = 1e20
    for ___ in xrange(1000):
        m = (l+r)/2
        circle2 = Circle(x2 - m * wx, y2 - m * wy, m * vmax)
        if circle.touches_other_circle(circle2):
            r = m
        else:
            l = m
    print t + l

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()