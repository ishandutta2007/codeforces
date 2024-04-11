x,y,z=gets.split.map &:to_i
p (4*(x*y/z+y*z/x+z*x/y+2*(x+y+z))**0.5).to_i