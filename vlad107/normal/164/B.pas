var
  ans,lb,rb,la,ra,n,m,i:longint;
  revb,b,a:array[0..2000500]of longint;

  function dist(x,y:longint):longint;
    begin
      if (y<x)then inc(y,m);
      dist:=y-x+1;
    end;
    
  procedure incl;
    begin
      inc(la);
      if (ra<la)then ra:=la;
      if (revb[a[la]]=0)then begin
        lb:=0;rb:=0;
        ra:=la-1;
        exit;
      end;
      lb:=revb[a[la]];
      if (rb=0)then rb:=lb;
    end;
    
  procedure incr;
    begin
      inc(ra);
      rb:=revb[a[ra]];
    end;

begin
  readln(n,m);
  for i:=1 to n do begin
    read(a[i]);
    a[n+i]:=a[i];
  end;
  for i:=1 to m do read(b[i]);
  for i:=1 to m do revb[b[i]]:=i;
  la:=0;ra:=0;
  lb:=0;rb:=0;
  ans:=0;
  for i:=1 to n do begin
    incl;
    if (lb=0)then continue;
    while ((ra+1)-la+1<=n)and(revb[a[ra+1]]<>0)and
            (dist(revb[a[la]],revb[a[ra+1]])<=m)and(dist(revb[a[la]],revb[a[ra+1]])>dist(revb[a[la]],revb[a[ra]]))do incr;
    if (ra-la+1>ans)then ans:=ra-la+1;            
  end;
  writeln(ans);
end.