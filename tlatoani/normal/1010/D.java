import java.util.Scanner;

public class MarsRover {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        int n = in.nextInt();
        Node[] nodesByIndex = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodesByIndex[i] = new Node(i);
        }
        for (int i = 1; i <= n; i++) {
            nodesByIndex[i].type = Type.valueOf(in.next());
            if (nodesByIndex[i].type == Type.IN) {
                nodesByIndex[i].value = 2 * in.nextInt();
            } else {
                nodesByIndex[i].child1 = nodesByIndex[in.nextInt()];
                nodesByIndex[i].child1.parent = nodesByIndex[i];
                if (nodesByIndex[i].type != Type.NOT) {
                    nodesByIndex[i].child2 = nodesByIndex[in.nextInt()];
                    nodesByIndex[i].child2.parent = nodesByIndex[i];
                }
            }
        }
        int nodeAmt = n;
        /*for (int i = 1; i <= n; i++) {
            if (i != 1 && nodesByIndex[i].type == Type.NOT) {
                continue;
            }
            if (nodesByIndex[i].child1 != null) {
                while (nodesByIndex[i].child1.type == Type.NOT && nodesByIndex[i].child1.child1.type == Type.NOT) {
                    nodesByIndex[i].child1 = nodesByIndex[i].child1.child1.child1;
                    nodesByIndex[i].child1.parent = nodesByIndex[i];
                    nodeAmt -= 2;
                }
                if (nodesByIndex[i].child2 != null) {
                    while (nodesByIndex[i].child2.type == Type.NOT && nodesByIndex[i].child2.child1.type == Type.NOT) {
                        nodesByIndex[i].child2 = nodesByIndex[i].child2.child1.child1;
                        nodesByIndex[i].child2.parent = nodesByIndex[i];
                        nodeAmt -= 2;
                    }
                }
            }
        }*/
        Node[] nodes = new Node[nodeAmt];
        nodes[0] = nodesByIndex[1];
        for (int i = 0, j = 1; i < nodeAmt; i++) {
            if (nodes[i].child1 != null) {
                nodes[j++] = nodes[i].child1;
                if (nodes[i].child2 != null) {
                    nodes[j++] = nodes[i].child2;
                }
            }
        }
        for (int i = nodeAmt - 1; i > 0; i--) {
            nodes[i].parent.subTreeSize += nodes[i].subTreeSize;
        }
        for (int i = 0; i < nodeAmt; i++) {
            if (nodes[i].segmentTree != null) {
                continue;
            }
            int len;
            Node curr;
            for (len = 0, curr = nodes[i]; curr != null; len++, curr = curr.child1) {
                curr.treePos = len;
                if (curr.child2 != null && curr.child2.subTreeSize > curr.child1.subTreeSize) {
                    Node temp = curr.child1;
                    curr.child1 = curr.child2;
                    curr.child2 = temp;
                }
            }
            SegmentTree segmentTree = new SegmentTree(nodes[i], 0, len - 1);
            for (curr = nodes[i]; curr != null; curr = curr.child1) {
                curr.segmentTree = segmentTree;
            }
        }
        for (int i = nodeAmt - 1; i >= 0; i--) {
            nodes[i].updateSegmentTree();
        }
        for (int i = 1; i <= n; i++) {
            if (nodesByIndex[i].type != Type.IN) {
                continue;
            }
            for (int j = 0; j < 2; j++) {
                nodesByIndex[i].value = 2 - nodesByIndex[i].value;
                for (Node curr = nodesByIndex[i]; curr != null; curr = curr.segmentTree.top.parent) {
                    curr.updateSegmentTree();
                }
                if (j == 0) {
                    builder.append(nodesByIndex[1].segmentTree.val[1] >> 1);
                }
            }
        }
        System.out.println(builder.toString());
    }

    enum Type {
        AND, OR, XOR, NOT, IN
    }

    static class Node {
        final int ix;
        Type type = null;
        Node parent = null;
        Node child1 = null;
        Node child2 = null;
        int value = -1;
        int subTreeSize = 1;
        SegmentTree segmentTree = null;
        int treePos = -1;

        Node(int ix) {
            this.ix = ix;
        }

        void updateSegmentTree() {
            int initVal;
            if (type == Type.IN) {
                initVal = value;
            } else if (type == Type.NOT) {
                initVal = 3;
            } else if (type == Type.AND) {
                initVal = child2.segmentTree.val[1] >> 1;
            } else if (type == Type.OR) {
                initVal = (child2.segmentTree.val[1] >> 1) + 1;
            } else {
                initVal = 1 + child2.segmentTree.val[1];
            }
            //System.out.println("ix = " + ix + ", initVal = " + initVal);
            segmentTree.update(treePos, initVal);
        }
    }

    static class SegmentTree {
        final Node top;
        final int[] val;
        final int treeFrom;
        final int treeTo;

        int combine(int a, int b) {
            switch (a) {
                case 0: return 0;
                case 2: return 2;
                case 1: return b;
                case 3: return (b + 2) % 4;
            }
            throw new IllegalStateException();
        }

        SegmentTree(Node top, int treeFrom, int treeTo) {
            this.top = top;
            this.treeFrom = treeFrom;
            this.treeTo = treeTo;
            int length = treeTo - treeFrom + 1;
            int l;
            for (l = 0; (1 << l) < length; l++);
            val = new int[1 << (l + 1)];
        }

        void update(int index, int newVal) {
            update(1, treeFrom, treeTo, index, newVal);
        }

        void update(int node, int segFrom, int segTo, int index, int newVal) {
            //System.out.println("node = " + node + ", segFrom = " + segFrom + ", segTo = " + segTo + ", index = " + index + ", newVal = " + newVal);
            if (segFrom == segTo) {
                val[node] = newVal;
            } else {
                int mid = (segFrom + segTo) >> 1;
                if (index <= mid) {
                    update(node << 1, segFrom, mid, index, newVal);
                } else {
                    update((node << 1) + 1, mid + 1, segTo, index, newVal);
                }
                val[node] = combine(val[node << 1], val[(node << 1) + 1]);
            }
        }
    }
}