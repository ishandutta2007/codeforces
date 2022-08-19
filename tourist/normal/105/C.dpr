{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  z,tmp,cnt,n,i,m,j,q,max,km: longint;
  stp: ansistring;
  lev,where,have,best,live,tr,tp,base,size,up: array [0..10010] of longint;
  name,nr: array [0..10010] of ansistring;

procedure rw(var s:ansistring);
var
  ch: char;
begin
  read(ch);
  while not (ch in ['a'..'z']) do read(ch);
  s:='';
  while ch in ['a'..'z'] do
  begin
    s:=s+ch;
    read(ch);
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  cnt:=0;
  for i:=1 to n do
  begin
    rw(name[i]);
    rw(stp);
    if stp = 'weapon' then begin tp[i]:=1; read(base[i],j,j); end else
    if stp = 'armor' then begin tp[i]:=2; read(j,base[i],j); end
    else begin tp[i]:=3; read(j,j,base[i]); end;
    read(size[i]);
    inc(cnt,size[i]);
  end;
  read(m);
  for i:=1 to m do
  begin
    rw(nr[i]);
    rw(stp);
    if stp = 'gladiator' then tr[i]:=1 else
    if stp = 'sentry' then tr[i]:=2
    else tr[i]:=3;
    read(up[i]);
    rw(stp);
    live[i]:=0;
    for j:=1 to n do
      if name[j] = stp then
      begin
        live[i]:=j;
        break;
      end;
  end;
  if cnt = m then
  begin
    for i:=1 to m do
      if tr[i] = tp[live[i]] then inc(base[live[i]],up[i]);
    for q:=1 to 3 do
    begin
      max:=-1; km:=0;
      for i:=1 to n do
        if (tp[i] = q) and (base[i] > max) then
        begin
          max:=base[i];
          km:=i;
        end;
      write(name[km],' ',size[km]);
      for i:=1 to m do
        if live[i] = km then write(' ',nr[i]);
      writeln;
    end;
    halt;
  end;
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if up[i] < up[j] then
      begin
        tmp:=up[i]; up[i]:=up[j]; up[j]:=tmp;
        stp:=nr[i]; nr[i]:=nr[j]; nr[j]:=stp;
        tmp:=tr[i]; tr[i]:=tr[j]; tr[j]:=tmp;
        tmp:=live[i]; live[i]:=live[j]; live[j]:=tmp;
      end;
  fillchar(where,sizeof(where),0);
  fillchar(have,sizeof(have),0);
  for z:=1 to 3 do
  begin
    max:=-1; km:=0;
    for i:=1 to n do
      if tp[i] = z then
      begin
        lev[i]:=base[i];
        q:=0;
        for j:=1 to m do
          if (q < size[i]) and (tr[j] = z) then
          begin
            inc(q);
            inc(lev[i],up[j]);
          end;
        if lev[i] > max then
        begin
          max:=lev[i];
          km:=i;
        end;
      end;
    best[z]:=km;
    q:=0;
    for j:=1 to m do
      if (q < size[km]) and (tr[j] = z) then
      begin
        inc(q);
        where[j]:=km;
      end;
    have[km]:=q;
  end;
  for i:=1 to m do
    if where[i] = 0 then
      for j:=1 to n do
        if have[j] < size[j] then
        begin
          inc(have[j]);
          where[i]:=j;
          break;
        end;
  for z:=1 to 3 do
  begin
    i:=best[z];
    write(name[i],' ',have[i]);
    for j:=1 to m do
      if where[j] = i then write(' ',nr[j]);
    writeln;
  end;
  close(input);
  close(output);
end.