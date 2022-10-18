const fi = '';
      fo = '';
var x1, y1, x2, y2, r1, r2: longint;
    d: real;
    tR, hR: real;
    
function kc(x1, y1, x2, y2: longint): real;
begin
 exit(sqrt(sqr(x1 - x2) + sqr(y1 - y2)));
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(x1, y1, r1);
 readln(x2, y2, r2);

 d:=kc(x1, y1, x2, y2);
 tR:=r1 + r2;
 hR:=abs(r1 - r2);

 if ((hR < d) and (d < tR)) or (hR = d) or (tR = d) then writeln('0.000000')
 else if (d > tR) then writeln((d - tR)/2:0:6)
 else if (d < hR) then writeln((hR - d)/2:0:6);

 close(input); close(output);
end.