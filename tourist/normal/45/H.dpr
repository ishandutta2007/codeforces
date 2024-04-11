{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
{$M 30000000}
var
  nl,q,leaves,cl,e,j,ii,kc,n,m,i,ss,ff: longint;
  ok: boolean;
  was: array [0..1010] of boolean;
  v,a,g: array [0..1010,0..1010] of longint;
  x,vl,kv,any,any2,c,md,de,pv: array [0..1010] of longint;

procedure rec(v,depth,pr:longint);
var
  j: longint;
begin
  was[v]:=True;
  pv[v]:=pr;
  de[v]:=depth;
  md[v]:=de[v];
  for j:=1 to n do
    if a[v,j] = 1 then
      if not was[j] then
      begin
        rec(j,depth+1,v);
        if md[j] < md[v] then md[v]:=md[j];
      end else
      if j <> pr then
        if de[j] < md[v] then md[v]:=de[j];
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  if n = 2 then
  begin
    writeln(-1);
    halt;
  end;
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
  begin
    read(ss,ff);
    a[ss,ff]:=1;
    a[ff,ss]:=1;
  end;
  fillchar(was,sizeof(was),False);
  rec(1,1,0);
  for i:=2 to n do
    if md[i] = de[i] then
    begin
      a[pv[i],i]:=2;
      a[i,pv[i]]:=2;
    end;
  fillchar(c,sizeof(c),0);
  kc:=0;
  for ii:=1 to n do
    if c[ii] = 0 then
    begin
      inc(kc);
      any[kc]:=ii;
      i:=1; e:=1;
      x[1]:=ii;
      c[ii]:=kc;
      while i <= e do
      begin
        for j:=1 to n do
          if (c[j] = 0) and (a[x[i],j] = 1) then
          begin
            inc(e);
            x[e]:=j;
            c[j]:=kc;
          end;
        inc(i);
      end;
      any2[kc]:=x[e];
    end;
  fillchar(g,sizeof(g),0);
  for i:=1 to n do
    for j:=1 to n do
      if a[i,j] = 2 then g[c[i],c[j]]:=1;
  n:=kc;
  if n = 1 then
  begin
    writeln(0);
    halt;
  end;
  if n = 2 then
  begin
    writeln(1);
    if a[any[1],any[2]] = 0 then writeln(any[1],' ',any[2]) else
    if any[1] <> any2[1] then writeln(any2[1],' ',any[2])
    else writeln(any[1],' ',any2[2]);
    halt;
  end;
  fillchar(kv,sizeof(kv),0);
  for i:=1 to n do
    for j:=1 to n do
      if g[i,j] = 1 then
      begin
        inc(kv[i]);
        v[i,kv[i]]:=j;
      end;
  leaves:=0;
  for i:=1 to n do
    if kv[i] = 1 then inc(leaves);
  for q:=1 to n do
    if kv[q] > 1 then
    begin
      fillchar(was,sizeof(was),False);
      was[q]:=True;
      ok:=True; cl:=0;
      for ii:=1 to n do
        if not was[ii] then
        begin
          i:=1; e:=1;
          x[1]:=ii;
          was[ii]:=True;
          while i <= e do
          begin
            for j:=1 to kv[x[i]] do
              if not was[v[x[i],j]] then
              begin
                inc(e);
                x[e]:=v[x[i],j];
                was[x[e]]:=True;
              end;
            inc(i);
          end;
          nl:=0;
          for i:=1 to e do
            if kv[x[i]] = 1 then
            begin
              inc(nl);
              inc(cl);
              vl[cl]:=x[i];
            end;
          if nl*2 > leaves then
          begin
            ok:=False;
            break;
          end;
        end;
      if ok then
      begin
        if cl and 1 = 1 then
        begin
          inc(cl);
          vl[cl]:=vl[cl-1];
        end;
        writeln(cl shr 1);
        for i:=1 to cl shr 1 do writeln(any[vl[i]],' ',any[vl[i+(cl shr 1)]]);
        halt;
      end;
    end;
  writeln('fail. =(');
  close(input);
  close(output);
end.