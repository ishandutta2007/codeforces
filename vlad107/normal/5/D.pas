const
  eps=1e-8;
var
  dd,b,c,ww,t,a,v,l,d,w,tv,vk,s,ts,qt,lt,rt:extended;
begin
  read(a,v,l,d,w);
  if (v<w)then w:=v;
  tv:=a*sqrt(2*d/a);
  if (tv<w)then w:=tv;
  lt:=0;rt:=1e9;
  while (rt-lt>eps)do begin
    t:=(lt+rt)/2;
    vk:=a*t;
    s:=a*t*t/2;
    if (vk>v)then begin
      vk:=v;
      tv:=v/a;
      s:=a*tv*tv/2+v*(t-tv);
    end;
    tv:=(vk-w)/a;
    ts:=tv*(vk+w)/2;
    if (s+ts>d)then rt:=t else lt:=t;
  end;
  qt:=t+tv;
  b:=2*w;
  c:=2*(d-l);
  dd:=b*b-4*a*c;
  t:=(-b+sqrt(dd))/(2*a);
  ww:=w+a*t;
  if (ww<=v)
    then begin
      writeln(t+qt:0:10);
      exit;
    end;
  t:=(v-w)/a;
  s:=t*(2*w+a*t)/2;
  t:=t+(l-d-s)/v;
  writeln(t+qt:0:10);
end.